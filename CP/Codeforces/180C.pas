{$H+}
uses
  math;
var
  s:string;
  i,a,b,x,y:longint;
begin
  readln(s);
  a:=0;
  b:=0;
  for i:=1 to length(s) do
    begin
      x:=0;
      y:=0;
      if s[i] in ['a'..'z'] then x:=1;
      if s[i] in ['A'..'Z'] then y:=1;
      b:=min(a,b)+y;
      a+=x;
    end;
  writeln(min(a,b));
end.
