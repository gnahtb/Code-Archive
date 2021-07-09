program ideone;
var
  a:array[0..100005] of longint;
  i,n,d,ans:longint;

function gcd(a,b:longint):longint;
begin
  if a mod b=0 then gcd:=b else gcd:=gcd(b, a mod b);
end;

procedure flip(var a,b:longint);
var
  t1,t2:longint;
begin
  t1:=a+b;
  t2:=a-b;
  a:=t1;
  b:=t2;
end;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  d:=a[1];
  for i:=2 to n do d:=gcd(d,a[i]);
  writeln('YES');
  if d>1 then
    begin
      write(0);
      exit;
    end;
  ans:=0;
  for i:=1 to n-1 do
    if odd(a[i]) and odd(a[i+1]) then
      begin
        inc(ans);
        flip(a[i],a[i+1]);
      end;
  for i:=1 to n-1 do
    if odd(a[i]) or odd(a[i+1]) then
      begin
        inc(ans,2);
        flip(a[i],a[i+1]);
        flip(a[i],a[i+1]);
      end;
  write(ans);
end.
