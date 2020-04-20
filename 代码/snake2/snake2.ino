#include <IRremote.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100//列
#define M 8//行

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
int map1[N][M];

typedef struct LinkList
{
  int x, y;
  struct LinkList *next;
} LL;

LL *head, *L1, *L2;
int kx, ky;

bool check(int x, int y);
void create();
bool eat(int x, int y);
void up();
void down();
void left();
void right();
void draw();
int tr(int f[M]);
void pri();

const long onw = 0x00FF18E7;
const long ons = 0x00FF4AB5;
const long ona = 0x00FF10EF;
const long ond = 0x00FF5AA5;

void setup()
{
  pinMode(RECV_PIN, INPUT);
  irrecv.enableIRIn();
  DDRD = 0xFF;

  head = (LL*)malloc(sizeof(LL));
  L1 = (LL*)malloc(sizeof(LL));
  L2 = (LL*)malloc(sizeof(LL));
  head->next = L1;
  L1->next = L2;
  L2->next = NULL;
  L1->x = 1; L1->y = 1;
  L2->x = 1; L2->y = 0;

  create();
  draw();
  pri();
}

void loop()
{
  if (irrecv.decode(&results))
  {
    if (results.value == onw) up(),draw(),pri();
    if (results.value == ons) down(),draw(),pri();
    if (results.value == ona) left(),draw(),pri();
    if (results.value == ond) right(),draw(),pri();

    irrecv.resume();
  }
}

bool check(int x, int y)
{
  y %= N;
  if (x < 1 || x >= M - 1) return false;
  LL *p = head;
  while (p->next != NULL)
  {
    p = p->next;
    if (p->x == x && p->y == y) return false;
  }
  return true;
}

void create()
{
  bool flag;
  do
  {
    flag = true;
    kx = rand() % (M - 2) + 1;
    ky = rand() % N;
    LL *p = head->next;
    while (flag && p != NULL)
    {
      if (p->x == kx && p->y == ky) flag = false;
      p = p->next;
    }
    if (flag) break;
  } while (1);
}

bool eat(int x, int y)
{
  y %= N;
  if (x != kx || y != ky) return false;
  LL *q;
  q = (LL*)malloc(sizeof(LL));
  q->next = head->next;
  head->next = q;
  q->x = x;
  q->y = y;
  create();
  return true;
}

void up()
{
  if (!check(head->next->x - 1, head->next->y)) return;
  if (eat(head->next->x - 1, head->next->y)) return;
  LL *p = head, *q;
  while (p->next->next != NULL) p = p->next;
  q = p->next;
  q->next = head->next;
  head->next = q;
  p->next = NULL;
  q->x = q->next->x - 1;
  q->y = q->next->y;
  return;
}

void down()
{
  if (!check(head->next->x + 1, head->next->y)) return;
  if (eat(head->next->x + 1, head->next->y)) return;
  LL *p = head, *q;
  while (p->next->next != NULL) p = p->next;
  q = p->next;
  q->next = head->next;
  head->next = q;
  p->next = NULL;
  q->x = q->next->x + 1;
  q->y = q->next->y;
  return;
}

void left()
{
  if (!check(head->next->x, head->next->y - 1)) return;
  if (eat(head->next->x, head->next->y - 1)) return;
  LL *p = head, *q;
  while (p->next->next != NULL) p = p->next;
  q = p->next;
  q->next = head->next;
  head->next = q;
  p->next = NULL;
  q->x = q->next->x;
  q->y = (q->next->y - 1 + N) % N;
  return;
}

void right()
{
  if (!check(head->next->x, head->next->y + 1)) return;
  if (eat(head->next->x, head->next->y + 1)) return;
  LL *p = head, *q;
  while (p->next->next != NULL) p = p->next;
  q = p->next;
  q->next = head->next;
  head->next = q;
  p->next = NULL;
  q->x = q->next->x;
  q->y = (q->next->y + 1 + N) % N;
  return;
}

void draw()
{
  memset(map1, 0, sizeof(map1));
  for (int i = 0; i < N; i++) map1[i][0] = map1[i][M - 1] = 1;
  for (LL *p = head->next; p != NULL; p = p->next) map1[p->y][p->x] = 1;
  map1[ky][kx] = 1;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
      map1[i][j] = (map1[i][j] ? 0 : 1);
  }
}

int tr(int f[M])
{
  int num = 0;
  for (int i = 0; i < M; i++) num += f[i] * (1 << (7 - i));
  return num;
}

void pri()
{
  for (int i = 0; i <= 10; i++)
  {
    for (int j = 0; j < N; j++)
    {
      PORTD = tr(map1[j]);
      delay(2);
    }
  }
}
