uses
  math;
const
  maxN=trunc(3e5)+5;
  maxM=trunc(3e5)+5;
type
  TEdge=record u,v,w:longint; end;
var
  e:array[0..maxM] of TEdge;
  f,p:array[0..maxN] of longint;
  n,m,ans:longint;

procedure enter;
var
  i:longint;
begin
  fillchar(e,sizeof(e),0);
  readln(n,m);
  for i:=1 to m do
    with e[i] do readln(u,v,w);
end;

procedure sort(l,r:longint);
var
  i,j,x:longint;
  y:TEdge;
begin
  i:=l;
  j:=r;
  x:=e[random(r-l+1)+l].w;
  repeat
    while e[i].w<x do inc(i);
    while x<e[j].w do dec(j);
    if i<=j then
      begin
        y:=e[i];
        e[i]:=e[j];
        e[j]:=y;
        inc(i);
        dec(j);
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

procedure solve;
var
  i,l,r:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(p,sizeof(p),0);
  l:=1;
  while l<=m do
    begin
      r:=l;
      while (r<m) and (e[l].w=e[r+1].w) do inc(r);
      for i:=l to r do f[i]:=p[e[i].u]+1;
      for i:=l to r do p[e[i].v]:=max(p[e[i].v],f[i]);
      l:=r+1;
    end;
  ans:=0;
  for i:=1 to m do ans:=max(ans,f[i]);
end;

begin
  enter;
  sort(1,m);
  solve;
  writeln(ans);
end.
