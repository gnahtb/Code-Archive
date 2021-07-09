{$MODE OBJFPC}
const
  maxN=trunc(2E5)+5;
var
  n,ans:longint;
  t,r,c:array[0..maxN] of longint;

procedure enter;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do read(t[i]);
end;

procedure solve;
var
  i:longint;
begin
  fillchar(r,sizeof(r),0);
  fillchar(c,sizeof(c),0);
  ans:=1;
  r[0]:=1;
  for i:=1 to n do
    if c[r[t[i]]]=t[i] then
      begin
        r[i]:=r[t[i]];
        c[r[t[i]]]:=i;
      end
    else
      begin
        inc(ans);
        r[i]:=ans;
        c[ans]:=i;
      end;
end;

begin
  enter;
  solve;
  writeln(ans);
end.
