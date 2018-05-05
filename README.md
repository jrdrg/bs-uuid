# bs-uuid

Bucklescript/Reason bindings for [uuid](https://www.npmjs.com/package/uuid)


# Install
```
yarn add bs-uuid
```
Add it to your bsconfig.json
```
"bs-dependencies": [
    ...
    "bs-uuid"
],
```

# Example

```
open BsUuid;

let v1 = Uuid.V1.create();
let v1WithOptions = Uuid.V1.createWithOptions(
    Uuid.V1.options(~msecs=1, ())
);

let v3 = Uuid.V3.create(
    ~name="Test", 
    ~namespace=`Uuid(Uuid.V3._DNS)
);

let v4 = Uuid.V4.create();

let v5 = Uuid.V5.create(
    ~name="Test", 
    ~namespace=`Uuid(Uuid.V5._DNS)
);

```

# Build
```
yarn run build
```

# Build + Watch

```
yarn run start
```
