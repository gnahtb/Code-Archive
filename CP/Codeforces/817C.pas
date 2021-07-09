var
  l,r,mid,ans,pos,n,s:int64;

function sumOfDigits(x:int64):int64;
var
  res:int64;
begin
  res:=0;
  while x>0 do
    begin
      res:=res+x mod 10;
      x:=x div 10;
    end;
  sumOfDigits:=res;
end;

begin
  readln(n,s);
  l:=0;
  r:=n+1;
  pos:=-1;
  while l<=r do
    begin
      mid:=(l+r) div 2;
      if mid-sumOfDigits(mid)>=s then
        begin
          pos:=mid;
          r:=mid-1;
        end
      else l:=mid+1;
    end;
  if pos<0 then ans:=0
  else ans:=n-pos+1;
  writeln(ans);
end.
