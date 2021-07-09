{$MODE OBJFPC}
uses
  gqueue,
  gvector,
  math;
const
  maxN=205;
type
  TPair=record fi,se:longint; end;
  TPairVector=specialize TVector<TPair>;
  TIntQueue=specialize TQueue<longint>;
var
  e:array[0..maxN] of TPair;
  a:array[0..maxN] of TPairVector;
  d:array[0..maxN] of longint;
  n,ans:longint;

function makePair(a,b:longint):TPair;
var
  pair:TPair;
begin
  pair.fi:=a;
  pair.se:=b;
  makePair:=pair;
end;

procedure enter;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n-1 do
    with e[i] do readln(fi,se);
end;

procedure build;
var
  i:longint;
begin
  for i:=1 to n do a[i]:=TPairVector.create;
  for i:=1 to n-1 do
    with e[i] do
      begin
        a[fi].pushback(makePair(se,i));
        a[se].pushback(makePair(fi,i));
      end;
end;

function BFS(s,id:longint):longint;
var
  queue:TIntQueue;
  free:array[0..maxN] of boolean;
  i,u,res:longint;
  t:TPair;
begin
  queue:=TIntQueue.create;
  fillchar(free,sizeof(free),true);
  fillchar(d,sizeof(d),0);
  queue.push(s);
  free[s]:=false;
  d[s]:=0;
  while not queue.isEmpty do
    begin
      u:=queue.front;
      for i:=0 to a[u].size-1 do
        begin
          t:=a[u][i];
          if (t.se<>id) and free[t.fi] then
            begin
              queue.push(t.fi);
              d[t.fi]:=d[u]+1;
              free[t.fi]:=false;
            end;
        end;
      queue.pop;
    end;
  res:=s;
  for i:=1 to n do
    if not free[i] and (d[i]>d[res]) then res:=i;
  BFS:=res;
end;

procedure solve;
var
  i,u,d1,d2:longint;
begin
  ans:=0;
  for i:=1 to n-1 do
    with e[i] do
      begin
        u:=BFS(fi,i);
        u:=BFS(u,i);
        d1:=d[u];
        u:=BFS(se,i);
        u:=BFS(u,i);
        d2:=d[u];
        ans:=max(ans,d1*d2);
      end;
end;

begin
  enter;
  build;
  solve;
  writeln(ans);
end.
