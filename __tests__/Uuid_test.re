open Jest;

describe("UUID", () => {
  describe("V1", () =>
    test("should create uuids based on ascending timestamp", () => {
      open Expect;
      let uuids = [
        Uuid.V1.create(),
        Uuid.V1.create(),
        Uuid.V1.create(),
        Uuid.V1.create(),
      ];
      let sorted =
        uuids
        |> List.sort((a, b) =>
             String.compare(Uuid.V1.toString(a), Uuid.V1.toString(b))
           );
      expect(uuids) |> toEqual(sorted);
    })
  );
  describe("V3", () =>
    test("should produce the same results as the uuid library tests", () => {
      open Expect;
      let create = Uuid.V3.create;
      expect(
        create(~name="hello.example.com", ~namespace=`Uuid(Uuid.V3._DNS))
        |> Uuid.V3.toString,
      )
      |> toBe("9125a8dc-52ee-365b-a5aa-81b0b3681cf6")
      |> ignore;
      expect(
        create(
          ~name="http://example.com/hello",
          ~namespace=`Uuid(Uuid.V3._DNS),
        )
        |> Uuid.V3.toString,
      )
      |> toBe("c6235813-3ba4-3801-ae84-e0a6ebb7d138")
      |> ignore;
      expect(
        create(
          ~name="hello",
          ~namespace=`Uuid("0f5abcd1-c194-47f3-905b-2df7263a084b"),
        )
        |> Uuid.V3.toString,
      )
      |> toBe("a981a0c2-68b1-35dc-bcfc-296e52ab01ec");
    })
  );
});
