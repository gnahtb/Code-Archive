var
  i,code,cnt,n:longint;
  s:string;
  a:array[0..100005] of int64;
  k:int64;
begin
  fillchar(a,sizeof(a),0);
  readln(n,k);
  cnt:=0;
  for i:=0 to n do
    begin
      readln(s);
      if s='?' then
        begin
          a[i]:=maxlongint;
          inc(cnt);
        end
      else val(s,a[i],code);
    end;
  if k=0 then
    begin
      if a[0]=0 then
        begin
          writeln('YES');
          halt;
        end;
      if a[0]<maxlongint then
        begin
          writeln('NO');
          halt;
        end;
      if (n-cnt+1) and 1=0 then writeln('NO') else writeln('YES');
    end
  else
    if cnt=0 then
      begin
        for i:=n downto 1 do
          begin
            a[i-1]:=a[i-1]+a[i]*k;
            if abs(a[i])>trunc(1E18) then
              begin
                writeln('NO');
                halt;
              end;
          end;
        if a[0]=0 then writeln('YES') else writeln('NO');
      end
    else if odd(n) then writeln('YES') else writeln('NO');
end.
