uses
  math;
const
  maxN=trunc(2e5)+5;
  maxM=trunc(4e5)+5;
type
  TEdge=record u,v:longint; end;
var
  n,m,s,t,ds,dt:longint;
  e:array[0..maxM] of TEdge;
  a:array[0..maxM] of longint;
  used:array[0..maxM] of boolean;
  root,depth:array[0..maxN] of longint;

procedure enter;
var
  i:longint;
begin
  readln(n,m);
  for i:=1 to m do
    with e[i] do readln(u,v);
  read(s,t,ds,dt);
end;

procedure init;
var
  i:longint;
begin
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
    with e[i] do a[i]:=ord((u=s) or (u=t))+ord((v=s) or (v=t));
end;

procedure swap(var x,y:longint);
var
  t:longint;
begin
  t:=x;
  x:=y;
  y:=t;
end;

procedure sort(l,r:longint);
var
  i,j,x:longint;
begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
      begin
        swap(e[i].u,e[j].u);
        swap(e[i].v,e[j].v);
        swap(a[i],a[j]);
        inc(i);
        dec(j);
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

function findSet(u:longint):longint;
begin
  while root[u]>0 do u:=root[u];
  findSet:=u;
end;

procedure makeSet(r1,r2:longint);
begin
  if depth[r1]<depth[r2] then
    begin
      root[r1]:=r2;
      depth[r2]:=max(depth[r2],depth[r1]+1);
    end
  else
    begin
      root[r2]:=r1;
      depth[r1]:=max(depth[r1],depth[r2]+1);
    end;
end;

procedure kruskal;
var
  deg:array[0..maxN] of longint;
  i,r1,r2:longint;
begin
  fillchar(deg,sizeof(deg),0);
  fillchar(root,sizeof(root),0);
  fillchar(depth,sizeof(depth),0);
  fillchar(used,sizeof(used),false);
  for i:=1 to m do
    with e[i] do
      begin
        r1:=findSet(u);
        r2:=findSet(v);
        if r1<>r2 then
          begin
            if (deg[s]=ds) and ((u=s) or (v=s)) then continue;
            if (deg[t]=dt) and ((u=t) or (v=t)) then continue;
            inc(deg[u]);
            inc(deg[v]);
            makeSet(r1,r2);
            used[i]:=true;
          end;
      end;
end;

procedure print;
var
  i:longint;
begin
  for i:=2 to n do
    if findSet(1)<>findSet(i) then
      begin
        write('No');
        exit;
      end;
  writeln('Yes');
  for i:=1 to m do
    if used[i] then with e[i] do writeln(u,' ',v);
end;

begin
  enter;
  init;
  sort(1,m);
  kruskal;
  print;
end.
