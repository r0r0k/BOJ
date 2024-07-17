1. array는 stack이나 data 영역의 첫번째 element의 주소를 가리킴

2. pointer는 heap영역의 첫번째 element의 주소를 가리킴

### 따라서, 둘다 parameter로 전달 방식은 같고 call by reference로 전달됨 
- parameter : `int *ptr` or `int arr[]`
- argument  : `val` (`&val`은 pointer나 array가 아닌 경우 call by reference로 주소를 넘기기 위함임)