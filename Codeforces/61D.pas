{$MODE OBJFPC}
uses
  gqueue;
const
  maxN=trunc(1E5)+5;
type
  TEdge=record u,v,w:longint; end;
  queueli=specialize TQueue<longint>;
var
  n:longint;
  ans:int64;
  e:array[0..maxN] of TEdge;
  h,d:array[0..maxN] of longint;
  a,id:array[0..maxN*2] of longint;

procedure enter;
var
  i:longint;
begin
  fillchar(h,sizeof(h),0);
  readln(n);
  ans:=0;
  for i:=1 to n-1 do
    with e[i] do
      begin
        readln(u,v,w);
        inc(h[u]); inc(h[v]);
        ans+=int64(w);
      end;
  ans:=ans << 1;
end;

procedure build;
var
  i:longint;
begin
  for i:=1 to n do h[i]:=h[i-1]+h[i];
  for i:=1 to n-1 do
    with e[i] do
      begin
        a[h[u]]:=v; a[h[v]]:=u;
        id[h[u]]:=i; id[h[v]]:=i;
        dec(h[u]); dec(h[v]);
      end;
  h[n+1]:=(n-1)*2;
end;

procedure BFS(u:longint);
var
  q:queueli;
  free:array[0..maxN] of boolean;
  i:longint;
begin
  q:=queueli.create;
  fillchar(d,sizeof(d),0);
  fillchar(free,sizeof(free),true);
  q.push(u);
  free[u]:=false;
  while not q.isEmpty do
    begin
      u:=q.front;
      q.pop;
      for i:=h[u]+1 to h[u+1] do
        if free[a[i]] then
          begin
            d[a[i]]:=d[u]+e[id[i]].w;
            free[a[i]]:=false;
            q.push(a[i]);
          end;
    end;
end;

procedure solve;
var
  i,t:longint;
begin
  BFS(1);
  t:=1;
  for i:=2 to n do
    if d[i]>d[t] then t:=i;
  ans-=int64(d[t]);
end;

begin
  enter;
  build;
  solve;
  writeln(ans);
end.
