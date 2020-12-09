const
  modulo=trunc(1E9)+9;
var
  n,m,k,l,ans:int64;

function pow(a,b:int64):int64;
var
  res:int64;
begin
  if b=0 then exit(1);
  res:=sqr(pow(a,b >> 1)) mod modulo;
  if b and 1=1 then res:=res*a mod modulo;
  pow:=res;
end;

procedure search;
var
  left,right,mid,tmp:int64;
begin
  left:=0; right:=m div k+1; l:=0;
  while left<=right do
    begin
      mid:=(left+right) >> 1;
      tmp:=m-mid*k;
      if (n-m+1)*(k-1)>=tmp then
        begin
          l:=mid;
          right:=mid-1;
        end
      else left:=mid+1;
    end;
end;

procedure solve;
var
  p,t,u:int64;
begin
  ans:=(pow(2,l+1)-2+modulo) mod modulo*k mod modulo;
  p:=n-m+1;
  t:=m-k*l;
  if t<=p then
    ans:=(ans+m-k*l) mod modulo
  else
    begin
      u:=t div p;
      ans:=(ans+u*p) mod modulo;
      t:=t mod p;
      ans:=(ans+t) mod modulo;
    end;
end;

begin
  readln(n,m,k);
  search;
  solve;
  writeln(ans);
end.
