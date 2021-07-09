{$MODE OBJFPC}
uses
  gpriorityqueue;
type
  pii=record fi,se:longint; end;
  cmp=class
  public
    class function c(a,b:pii):boolean; inline;
  end;
  pq=specialize TPriorityQueue<pii,cmp>;
var
  cnt,pos:array[0..100005] of longint;
  isRecord:array[0..100005] of boolean;
  n,ans:longint;
  heap:pq;

class function cmp.c(a,b:pii):boolean;
begin
  c:=a.fi>b.fi;
end;

function make_pair(fi,se:longint):pii;
var
  pair:pii;
begin
  pair.fi:=fi;
  pair.se:=se;
  make_pair:=pair;
end;

procedure enter;
var
  i,t:longint;
begin
  fillchar(pos,sizeof(pos),0);
  readln(n);
  for i:=1 to n do
    begin
      read(t);
      pos[t]:=i;
    end;
end;

procedure solve;
var
  i,best,cur,tmp:longint;
  t1,t2:pii;
begin
  fillchar(cnt,sizeof(cnt),0);
  fillchar(isRecord,sizeof(isRecord),false);
  heap:=pq.create;
  heap.push(make_pair(pos[n],n));
  isRecord[n]:=true;
  for i:=n-1 downto 1 do
    begin
      t2:=make_pair(maxlongint,maxlongint);
      t1:=heap.top;
      heap.pop;
      if not heap.isEmpty then t2:=heap.top;
      if (t2.fi>pos[i]) and (t1.fi<pos[i]) then inc(cnt[t1.se]);
      if t1.fi>pos[i] then isRecord[i]:=true;
      heap.push(t1);
      heap.push(make_pair(pos[i],i));
    end;
  cur:=0;
  for i:=1 to n do
    if isRecord[i] then inc(cur);
  best:=-1;
  ans:=0;
  for i:=1 to n do
    begin
      tmp:=cur+cnt[i];
      if isRecord[i] then dec(tmp);
      if tmp>best then
        begin
          best:=tmp;
          ans:=i;
        end;
    end;
end;

begin
  enter;
  solve;
  writeln(ans);
end.
