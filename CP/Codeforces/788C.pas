{$MODE OBJFPC}
uses
  gqueue,
  gvector;
type
  vectorli=specialize TVector<longint>;
  queueli=specialize TQueue<longint>;
var
  a:array[-1005..1005] of boolean;
  free:array[-1000005..1000005] of boolean;
  d:array[-1000005..1000005] of longint;
  e:vectorli;
  queue:queueli;
  n,k,i,t:longint;

procedure BFS;
var
  u,v:longint;
begin
  queue:=queueli.create;
  fillchar(free,sizeof(free),true);
  fillchar(d,sizeof(d),0);
  d[0]:=0;
  queue.push(0);
  while not queue.isEmpty do
    begin
      u:=queue.front;
      queue.pop;
      for i:=0 to e.size-1 do
        begin
          v:=u+e[i];
          if (abs(v)<=1000000) and free[v] then
            begin
              queue.push(v);
              d[v]:=d[u]+1;
              free[v]:=false;
            end;
          if not free[0] then exit;
        end;
    end;
end;

begin
  fillchar(a,sizeof(a),false);
  e:=vectorli.create;
  readln(n,k);
  for i:=1 to k do
    begin
      read(t);
      a[t-n]:=true;
    end;
  for i:=-1000 to 1000 do
    if a[i] then e.pushback(i);
  BFS;
  if d[0]>0 then writeln(d[0]) else writeln(-1);
end.
