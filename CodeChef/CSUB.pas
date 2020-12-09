{$H+}
var
  t,n,m,i,cnt:longint;
  ans:int64;
  s:string;
begin
  readln(t);
  while t>0 do
    begin
      readln(n);
      readln(s);
      cnt:=0;
      for i:=1 to n do
        if s[i]='1' then inc(cnt);
      ans:=int64(cnt+1)*int64(cnt) div 2;
      writeln(ans);
      dec(t);
    end;
end.