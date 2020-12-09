{$MODE OBJFPC}
uses
  gpriorityqueue,gvector,math;
const
  maxN=trunc(3E5)+5;
  maxM=trunc(3E5)+5;
type
  pii=record fi,se:longint; end;
  TCompare=class public class function c(a,b:pii):boolean; inline; end;
  vectorli=specialize TVector<longint>;
  pqpii=specialize TPriorityQueue<pii,TCompare>;
var
  n,m,ans:longint;
  e:array[0..maxM] of pii;
  c:array[0..maxN] of char;
  a:array[0..maxN] of vectorli;
  d:array[0..maxN] of longint;
  f:array[0..maxN,'a'..'z'] of longint;
  free:array[0..maxN] of boolean;
  pq:pqpii;

class function TCompare.c(a,b:pii):boolean; inline;
begin
  c:=a.se>b.se;
end;

function makepair(x,y:longint):pii;
var
  p:pii;
begin
  p.fi:=x; p.se:=y; makepair:=p;
end;

procedure enter;
var
  i:longint;
begin
  readln(n,m);
  for i:=1 to n do read(c[i]);
  for i:=1 to m do readln(e[i].fi,e[i].se);
end;

procedure sort(l,r:longint);
var
  i,j:longint;
  x,y:pii;
begin
  i:=l; j:=r; x:=e[(l+r) >> 1];
  repeat
    while (e[i].fi<x.fi) or ((e[i].fi=x.fi) and (e[i].se<x.se)) do inc(i);
    while (x.fi<e[j].fi) or ((x.fi=e[j].fi) and (x.se<e[j].se)) do dec(j);
    if i<=j then
      begin
        y:=e[i]; e[i]:=e[j]; e[j]:=y;
        inc(i); dec(j);
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

procedure unique;
var
  i,j,x:longint;
begin
  i:=1; x:=0;
  while i<=m do
    begin
      j:=i;
      while (j<m) and (e[i].fi=e[j+1].fi) and (e[i].se=e[j+1].se) do inc(j);
      inc(x); e[x]:=e[i];
      i:=j+1;
    end;
  m:=x;
end;

procedure build;
var
  i:longint;
begin
  fillchar(d,sizeof(d),0);
  for i:=1 to n do a[i]:=vectorli.create;
  for i:=1 to m do
    begin
      a[e[i].fi].pushback(e[i].se);
      inc(d[e[i].se]);
    end;
end;

procedure solve;
var
  i,v:longint;
  j:char;
  u:pii;
begin
  fillchar(free,sizeof(free),true);
  fillchar(f,sizeof(f),0);
  pq:=pqpii.create;
  for i:=1 to n do pq.push(makepair(i,d[i]));
  repeat
    repeat u:=pq.top; pq.pop; until free[u.fi] or pq.isEmpty;
    if u.se>0 then break;
    free[u.fi]:=false;
    for i:=0 to a[u.fi].size-1 do
      begin
        v:=a[u.fi][i];
        if free[v] then
          begin
            for j:='a' to 'z' do f[v,j]:=max(f[v,j],f[u.fi,j]);
            f[v,c[u.fi]]:=max(f[v,c[u.fi]],f[u.fi,c[u.fi]]+1);
            dec(d[v]);
            pq.push(makepair(v,d[v]));
          end;
      end;
  until pq.isEmpty;
  for i:=1 to n do
    if free[i] then begin writeln(-1); halt; end;
  ans:=0;
  for i:=1 to n do
    begin
      for j:='a' to 'z' do ans:=max(ans,f[i,j]);
      ans:=max(ans,f[i,c[i]]+1);
    end;
end;

begin
  enter;
  sort(1,m);
  unique;
  build;
  solve;
  writeln(ans);
end.
