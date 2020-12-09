{$MODE OBJFPC}
uses
  math,
  gvector;
type
  vectori64=specialize TVector<int64>;
var
  n,m,ans:int64;
  s:vectori64;

function upper_bound(x:int64):longint;
var
  left,right,mid,pos:longint;
begin
  left:=0;
  right:=s.size-1;
  pos:=-1;
  while left<=right do
    begin
      mid:=(left+right) >> 1;
      if s[mid]>=x then
        begin
          pos:=mid;
          right:=mid-1;
        end
      else left:=mid+1;
    end;
  upper_bound:=pos;
end;

function lower_bound(x:int64):longint;
var
  left,right,mid,pos:longint;
begin
  left:=0;
  right:=s.size-1;
  pos:=-1;
  while left<=right do
    begin
      mid:=(left+right) >> 1;
      if s[mid]<=x then
        begin
          pos:=mid;
          left:=mid+1;
        end
      else right:=mid-1;
    end;
  lower_bound:=pos;
end;

function check(x:int64):boolean;
var
  t,u,v:int64;
begin
  u:=-(x << 1);
  v:=u-sqr(x) mod u;
  t:=min(m,u*n-sqr(x));
  if t<=0 then exit(false);
  if t>=v then exit(true);
  check:=false;
end;

procedure solve;
var
  i,l,h:longint;
begin
  ans:=0;
  s:=vectori64.create;
  for i:=0 to n do s.pushback(sqr(int64(i)));
  for i:=1 to n do
    begin
      ans:=ans+min(sqr(int64(i)),m);
      l:=upper_bound(sqr(int64(i))-m);
      h:=lower_bound(sqr(int64(i))-1);
      if l<=h then ans:=ans-int64(h-l+1);
    end;
  ans:=ans << 1;
  for i:=-10000000 to -1 do
    if check(int64(i)) then inc(ans);
end;

begin
  readln(n,m);
  solve;
  writeln(ans);
end.
