uses
  math;
var
  n,x,t,tmp,p,ans:int64;
  i,d:longint;
begin
  readln(n);
  if n<5 then
    begin
      write(n*(n-1) div 2);
      halt;
    end;
  x:=999999999;
  for i:=9 downto 1 do
    begin
      ans:=0;
      for d:=0 to 8 do
        begin
          t:=d*(10**int64(i))+x;
          tmp:=t-min(t-1,n);
          if tmp<n then
            begin
              p:=(tmp+min(t-1,n)) div 2;
              ans:=ans+p-tmp+1;
            end;
        end;
      if ans>0 then break;
      x:=x div 10;
    end;
  writeln(ans);
end.
