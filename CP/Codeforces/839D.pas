{$MODE OBJFPC}
const
  modulo=trunc(1E9)+7;
var
  f,c,s:array[0..1000005] of longint;
  ans:int64;

procedure prep;
var
  i,pw:longint;
begin
  fillchar(s,sizeof(s),0);
  s[1]:=1; pw:=2;
  for i:=2 to 200000 do
    begin
      s[i]:=((s[i-1] << 1) mod modulo+pw) mod modulo;
      pw:=(pw << 1) mod modulo;
    end;
end;

procedure enter;
var
  a,i,n:longint;
begin
  fillchar(c,sizeof(c),0);
  readln(n);
  for n:=n downto 1 do
    begin
      read(a);
      for i:=1 to trunc(sqrt(a)) do
        if a mod i=0 then
          begin
            if i>1 then inc(c[i]);
            if i<>a div i then inc(c[a div i]);
          end;
    end;
end;

procedure solve;
var
  i,j:longint;
begin
  fillchar(f,sizeof(f),0);
  ans:=0;
  for i:=trunc(1E6) downto 2 do
    begin
      f[i]:=s[c[i]];
      for j:=2 to trunc(1E6) div i do
        f[i]:=(f[i]-f[i*j]+modulo) mod modulo;
    end;
  for i:=2 to trunc(1E6) do ans:=(ans+int64(i)*int64(f[i]) mod modulo) mod modulo;
end;

begin
  prep;
  enter;
  solve;
  writeln(ans);
end.
