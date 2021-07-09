{$MODE OBJFPC}
{$H+}
var
  s,t:string;
  i:longint;
begin
  readln(s);
  t:='*';
  for i:=1 to length(s) do
    if s[i]<>t[length(t)] then t:=t+s[i]
    else delete(t,length(t),1);
  if length(t)>1 then writeln('NO') else writeln('YES');
end.
