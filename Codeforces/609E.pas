{$MODE OBJFPC}
uses
  math,gvector;
const
  maxN=trunc(2E5)+5;
  maxM=trunc(2E5)+5;
type
  TEdge=record o,u,v,w:longint; end;
  pii=record fi,se:longint; end;
  vectorpii=specialize TVector<pii>;
var
  n,m:longint;
  e:array[0..maxM] of TEdge;
  c:array[0..maxM] of boolean;
  r,d:array[0..maxN] of longint;
  p,f:array[0..maxN,0..20] of longint;
  a:array[0..maxN] of vectorpii;
  ans:array[0..maxN] of int64;

function make_pair(fi,se:longint):pii;
var
  p:pii;
begin
  p.fi:=fi; p.se:=se; make_pair:=p;
end;

procedure swap(var x,y:longint);
var
  t:longint;
begin
  t:=x; x:=y; y:=t;
end;

procedure enter;
var
  i:longint;
begin
  readln(n,m);
  for i:=1 to m do
    with e[i] do
      begin
        o:=i;
        readln(u,v,w);
      end;
end;

procedure sort(l,r:longint);
var
  i,j:longint;
  x,y:TEdge;
begin
  i:=l; j:=r;
  x:=e[(l+r) >> 1];
  repeat
    while e[i].w<x.w do inc(i);
    while x.w<e[j].w do dec(j);
    if i<=j then
      begin
        y:=e[i]; e[i]:=e[j]; e[j]:=y;
        inc(i); dec(j);
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

function findSet(u:longint):longint;
begin
  while r[u]>0 do u:=r[u];
  findSet:=u;
end;

procedure makeSet(p,q:longint);
begin
  if d[p]<d[q] then
    begin
      r[p]:=q;
      d[q]:=max(d[q],d[p]+1);
    end
  else
    begin
      r[q]:=p;
      d[p]:=max(d[p],d[q]+1);
    end;
end;

procedure kruskal;
var
  i,x,y:longint;
begin
  fillchar(c,sizeof(c),false);
  fillchar(r,sizeof(r),0);
  fillchar(d,sizeof(d),0);
  for i:=1 to m do
    with e[i] do
      begin
        x:=findSet(u); y:=findSet(v);
        if x<>y then
          begin
            makeSet(x,y);
            c[i]:=true;
          end;
      end;
end;

procedure buildGraph;
var
  i:longint;
begin
  for i:=1 to n do a[i]:=vectorpii.create;
  for i:=1 to m do
    if c[i] then
      begin
        a[e[i].u].pushback(make_pair(e[i].v,e[i].w));
        a[e[i].v].pushback(make_pair(e[i].u,e[i].w));
      end;
end;

procedure DFS(u:longint);
var
  i,v,w:longint;
begin
  for i:=0 to a[u].size-1 do
    begin
      v:=a[u][i].fi; w:=a[u][i].se;
      if v<>p[u,0] then
        begin
          d[v]:=d[u]+1;
          p[v,0]:=u; f[v,0]:=w;
          DFS(v);
        end;
    end;
end;

procedure buildLCA;
var
  i,j:longint;
begin
  fillchar(d,sizeof(d),0);
  fillchar(f,sizeof(f),0);
  fillchar(p,sizeof(p),0);
  DFS(1);
  for j:=1 to 20 do
    for i:=1 to n do
      begin
        f[i,j]:=max(f[i,j-1],f[p[i,j-1],j-1]);
        p[i,j]:=p[p[i,j-1],j-1];
      end;
end;

function getLCA(u,v:longint):longint;
var
  delta,i,res:longint;
begin
  if d[u]<d[v] then swap(u,v);
  res:=0;
  delta:=d[u]-d[v];
  for i:=20 downto 0 do
    if (delta >> i) and 1=1 then
      begin
        res:=max(res,f[u,i]);
        u:=p[u,i];
      end;
  if u<>v then
    begin
      for i:=20 downto 0 do
        if p[u,i]<>p[v,i] then
          begin
            res:=max(res,max(f[u,i],f[v,i]));
            u:=p[u,i]; v:=p[v,i];
          end;
      res:=max(res,max(f[u,0],f[v,0]));
    end;
  getLCA:=res;
end;

procedure solve;
var
  sum:int64;
  i,t:longint;
begin
  fillchar(ans,sizeof(ans),0);
  sum:=0;
  for i:=1 to m do
    if c[i] then sum:=sum+int64(e[i].w);
  for i:=1 to m do
    with e[i] do
      begin
        t:=getLCA(u,v);
        ans[o]:=sum-int64(t)+int64(w);
      end;
  for i:=1 to m do writeln(ans[i]);
end;

begin
  enter;
  sort(1,m);
  kruskal;
  buildGraph;
  buildLCA;
  solve;
end.
