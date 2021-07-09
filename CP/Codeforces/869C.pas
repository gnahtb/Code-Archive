const
  module=998244353;
var
  cb:array[0..5005,0..5005] of int64;
  p:array[0..5005] of int64;
  a,b,c,ans,ans1,ans2,ans3:int64;

procedure init;
var
  i,j:longint;
begin
  fillchar(cb,sizeof(cb),0);
  cb[0,0]:=1;
  for i:=1 to 5000 do
    begin
      cb[i,0]:=1;
      for j:=1 to i do
        cb[i,j]:=(cb[i-1,j]+cb[i-1,j-1]) mod module;
    end;
  p[1]:=1;
  for i:=2 to 5000 do p[i]:=p[i-1]*i mod module;
end;

procedure solve1;
var
  i:longint;
  tmp:int64;
begin
  ans1:=1;
  for i:=1 to a do
    begin
      tmp:=cb[a,i]*cb[b,i] mod module*p[i] mod module;
      ans1:=(ans1+tmp) mod module;
    end;
end;

procedure solve2;
var
  i:longint;
  tmp:int64;
begin
  ans2:=1;
  for i:=1 to a do
    begin
      tmp:=cb[a,i]*cb[c,i] mod module*p[i] mod module;
      ans2:=(ans2+tmp) mod module;
    end;
end;

procedure solve3;
var
  i:longint;
  tmp:int64;
begin
  ans3:=1;
  for i:=1 to b do
    begin
      tmp:=cb[b,i]*cb[c,i] mod module*p[i] mod module;
      ans3:=(ans3+tmp) mod module;
    end;
end;

begin
  init;
  readln(a,b,c);
  solve1;
  solve2;
  solve3;
  ans:=ans1*ans2 mod module*ans3 mod module;
  write(ans);
end.
