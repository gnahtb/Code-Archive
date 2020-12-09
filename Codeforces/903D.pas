{$MODE OBJFPC, H+}
const
  maxN=trunc(2E5)+5;
type
  TBigNum=string;
var
  a,b,cnt:array[0..maxN] of longint;
  f:array[0..maxN] of int64;
  n,m:longint;
  ans:TBigNum;

function toBigNum(x:int64):TBigNum;
var
  s:TBigNum;
begin
  str(x,s);
  toBigNum:=s;
end;

function isLess(a,b:TBigNum):boolean;
begin
  while length(a)<length(b) do a:='0'+a;
  while length(b)<length(a) do b:='0'+b;
  isLess:=a<b;
end;

function add(a,b:TBigNum):TBigNum;
var
  sum,carry,i,x,y:longint;
  c:TBigNum;
begin
  carry:=0;
  c:='';
  while length(a)<length(b) do a:='0'+a;
  while length(b)<length(a) do b:='0'+b;
  for i:=length(a) downto 1 do
    begin
      x:=ord(a[i])-48;
      y:=ord(b[i])-48;
      sum:=x+y+carry;
      carry:=sum div 10;
      c:=chr(sum mod 10+48)+c;
    end;
  if carry>0 then c:='1'+c;
  add:=c;
end;

function sub(a,b:TBigNum):TBigNum;
var
  s,borrow,i:longint;
  c:TBigNum;
begin
  borrow:=0;
  c:='';
  while length(a)<length(b) do a:='0'+a;
  while length(b)<length(a) do b:='0'+b;
  for i:=length(a) downto 1 do
    begin
      s:=ord(a[i])-ord(b[i])-borrow;
      if s<0 then
        begin
          s:=s+10;
          borrow:=1;
        end
      else borrow:=0;
      c:=chr(s+48)+c;
    end;
  while (length(c)>1) and (c[1]='0') do delete(c,1,1);
  sub:=c;
end;

procedure enter;
var
  i:longint;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);
      b[i]:=a[i];
    end;
end;

procedure sort(l,r:longint);
var
  i,j,x,y:longint;
begin
  i:=l;
  j:=r;
  x:=b[(l+r) >> 1];
  repeat
    while b[i]<x do inc(i);
    while x<b[j] do dec(j);
    if i<=j then
      begin
        y:=b[i]; b[i]:=b[j]; b[j]:=y;
        inc(i); dec(j);
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

procedure compress;
var
  i,j:longint;
begin
  m:=0;
  i:=1;
  while i<=n do
    begin
      j:=i;
      while (j<n) and (b[j+1]=b[i]) do inc(j);
      inc(m);
      b[m]:=b[i];
      i:=j+1;
    end;
  for i:=m+1 to n do b[i]:=0;
end;

function getIndex(x:longint):longint;
var
  left,right,mid:longint;
begin
  left:=1;
  right:=m;
  while left<=right do
    begin
      mid:=(left+right) >> 1;
      if b[mid]=x then exit(mid);
      if b[mid]>x then right:=mid-1;
      if b[mid]<x then left:=mid+1;
    end;
  getIndex:=0;
end;

procedure calc;
var
  i:longint;
  suff:int64=0;
begin
  fillchar(cnt,sizeof(cnt),0);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    begin
      inc(cnt[getIndex(a[i])]);
      suff:=suff+int64(a[i]);
    end;
  for i:=1 to n-1 do
    begin
      dec(cnt[getIndex(a[i])]);
      suff:=suff-int64(a[i]);
      f[i]:=suff-int64(a[i])*int64(n-i);
      f[i]:=f[i]-cnt[getIndex(a[i]+1)]+cnt[getIndex(a[i]-1)];
    end;
end;

procedure solve;
var
  pos,neg,tmp:TBigNum;
  i:longint;
begin
  pos:='0';
  neg:='0';
  for i:=1 to n-1 do
    begin
      tmp:=toBigNum(abs(f[i]));
      if f[i]>0 then pos:=add(pos,tmp);
      if f[i]<0 then neg:=add(neg,tmp);
    end;
  if isLess(pos,neg) then ans:='-'+sub(neg,pos)
  else ans:=sub(pos,neg);
end;

begin
  enter;
  sort(1,n);
  compress;
  calc;
  solve;
  writeln(ans);
end.
