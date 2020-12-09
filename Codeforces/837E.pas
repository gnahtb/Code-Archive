{$MODE OBJFPC}
uses
  math;
var
  x,y,g,ans,tmp,w:int64;
  i:longint;

function gcd(a,b:int64):int64;
begin
  if a mod b=0 then gcd:=b else gcd:=gcd(b,a mod b);
end;

begin
  readln(x,y);
  ans:=0;
  while y>0 do
    begin
      g:=gcd(x,y);
      x:=x div g;
      y:=y div g;
      tmp:=0;
      for i:=1 to trunc(sqrt(x)) do
        if x mod int64(i)=0 then
          begin
            if i>1 then tmp:=max(tmp,y div int64(i)*int64(i));
            w:=x div int64(i);
            if w>1 then tmp:=max(tmp,y div w*w);
          end;
      ans:=ans+y-tmp;
      y:=tmp;
    end;
  writeln(ans);
end.
