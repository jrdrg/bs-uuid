open Jest;

describe("UUID", () =>
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
  )
);
