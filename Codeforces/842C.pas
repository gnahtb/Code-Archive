uses
  math;
const
  maxN=trunc(2e5)+5;
type
  TEdge=record
    x,y:longint;
  end;
var
  a,head,d,ans:array[0..maxN] of longint;
  adj:array[0..maxN*2] of longint;
  e:array[0..maxN] of TEdge;
  free:array[0..maxN] of boolean;
  n:longint;

procedure enter;
var
  i:longint;
begin
  fillchar(head,sizeof(head),0);
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
    with e[i] do
      begin
        readln(x,y);
        inc(head[x]);
        inc(head[y]);
      end;
end;

procedure build;
var
  i:longint;
begin
  for i:=2 to n do head[i]:=head[i]+head[i-1];
  for i:=1 to n-1 do
    with e[i] do
      begin
        adj[head[x]]:=y;
        adj[head[y]]:=x;
        dec(head[x]);
        dec(head[y]);
      end;
  head[n+1]:=(n-1)*2;
end;

function GCD(p,q:longint):longint;
begin
  if p mod q=0 then GCD:=q else GCD:=GCD(q,p mod q);
end;

procedure DFS(u,g,cnt:longint);
var
  tmp,i,k:longint;
begin
  free[u]:=false;
  tmp:=GCD(g,a[u]);
  ans[u]:=max(g,tmp);
  for i:=1 to trunc(sqrt(a[u])) do
    if a[u] mod i=0 then
      begin
        k:=a[u] div i;
        if d[i]>=cnt-1 then ans[u]:=max(ans[u],i);
        if d[k]>=cnt-1 then ans[u]:=max(ans[u],k);
        inc(d[i]);
        if k<>i then inc(d[k]);
      end;
  for i:=head[u]+1 to head[u+1] do
    if free[adj[i]] then
      DFS(adj[i],tmp,cnt+1);
  for i:=1 to trunc(sqrt(a[u])) do
    if a[u] mod i=0 then
      begin
        dec(d[i]);
        if a[u] div i<>i then dec(d[a[u] div i]);
      end;
end;

procedure solve;
var
  i:longint;
begin
  fillchar(d,sizeof(d),0);
  fillchar(free,sizeof(free),true);
  DFS(1,a[1],0);
  for i:=1 to n do write(ans[i],' ');
end;

begin
  enter;
  build;
  solve;
end.

