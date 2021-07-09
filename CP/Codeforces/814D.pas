uses
  math;
type
  TCircle=record x,y,r:extended; end;
var
  c:array[0..1005] of TCircle;
  a:array[0..1005] of extended;
  e:array[0..1005,0..1005] of boolean;
  free:array[0..1005] of boolean;
  d:array[0..1005] of longint;
  n:longint;
  ans:extended;

procedure enter;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do
    with c[i] do readln(x,y,r);
end;

procedure sort;
var
  i,j:longint;
  t:TCircle;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if c[i].r<c[j].r then
        begin
          t:=c[i]; c[i]:=c[j]; c[j]:=t;
        end;
end;

procedure build;
var
  i,j:longint;
  d:extended;
begin
  fillchar(a,sizeof(a),0);
  fillchar(e,sizeof(e),false);
  for i:=1 to n do
    begin
      a[i]:=sqr(c[i].r)*pi;
      for j:=i+1 to n do
        begin
          d:=sqrt(sqr(c[i].x-c[j].x)+sqr(c[i].y-c[j].y));
          if d<=c[i].r-c[j].r then e[i,j]:=true;
        end;
    end;
end;

procedure DFS(u,p:longint);
var
  v:longint;
begin
  free[u]:=false;
  d[u]:=d[p]+1;
  for v:=1 to n do
    if e[u,v] and free[v] then DFS(v,u);
end;

procedure solve;
var
  u,i,cnt:longint;
begin
  fillchar(free,sizeof(free),true);
  for u:=1 to n do
    if free[u] then
      begin
        cnt:=0;
        for i:=1 to n do if e[i,u] then inc(cnt);
        if cnt=0 then DFS(u,0);
      end;
  ans:=0;
  for u:=1 to n do
    if d[u]<3 then ans:=ans+a[u]
    else
      if odd(d[u]) then ans:=ans-a[u]
      else ans:=ans+a[u];
end;

begin
  enter;
  sort;
  build;
  solve;
  writeln(ans:0:10);
end.
