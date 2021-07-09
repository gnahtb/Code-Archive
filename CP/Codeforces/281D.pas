{$MODE OBJFPC}
uses
  gstack,math;
const
  maxN=trunc(1E5)+5;
type
  stackli=specialize TStack<longint>;
var
  n,ans:longint;
  s:array[0..maxN] of longint;
  stack:stackli;

procedure enter;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do read(s[i]);
end;

procedure solve;
var
  i:longint;
begin
  ans:=0;
  stack:=stackli.create;
  stack.push(maxlongint);
  for i:=1 to n do
    begin
      while stack.top<=s[i] do
        begin
          ans:=max(ans,s[i] xor stack.top);
          stack.pop;
        end;
      stack.push(s[i]);
    end;

  stack:=stackli.create;
  stack.push(maxlongint);
  for i:=n downto 1 do
    begin
      while stack.top<=s[i] do
        begin
          ans:=max(ans,s[i] xor stack.top);
          stack.pop;
        end;
      stack.push(s[i]);
    end;
end;

begin
  enter;
  solve;
  writeln(ans);
end.
