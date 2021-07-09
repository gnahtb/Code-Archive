{$MODE OBJFPC}
uses
  gvector;
const
  maxN=trunc(2e5)+5;
  module=trunc(1e9)+7;
type
  TIntVector=specialize TVector<longint>;
var
  a,d,free:array[0..maxN] of longint;
  c:TIntVector;
  n:longint;
  ans:int64;

procedure enter;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
end;

procedure DFS(u,l:longint);
var
  t:longint;
begin
  free[u]:=1;
  d[u]:=l;
  if free[a[u]]=0 then DFS(a[u],l+1)
  else if free[a[u]]=1 then
    begin
      t:=d[u]-d[a[u]]+1;
      c.pushback(t);
    end;
  free[u]:=2;
end;

procedure findCycle;
var
  i:longint;
begin
  fillchar(free,sizeof(free),0);
  c:=TIntVector.create;
  for i:=1 to n do
    if free[i]=0 then DFS(i,0);
end;

procedure solve;
var
  i:longint;
  p:array[0..maxN] of int64;
begin
  fillchar(p,sizeof(p),0);
  p[0]:=1;
  for i:=1 to n do p[i]:=p[i-1]*2 mod module;
  ans:=1;
  for i:=0 to c.size-1 do
    begin
      n-=c[i];
      ans:=ans*(p[c[i]]-2+module) mod module;
    end;
  ans:=ans*p[n] mod module;
end;

begin
  enter;
  findCycle;
  solve;
  writeln(ans);
end.
