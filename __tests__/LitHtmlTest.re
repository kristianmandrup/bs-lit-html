module D = Webapi.Dom;
module Doc = D.Document;
let appElement = Doc.getElementById("app", D.document);

open Jest;
open LitHtml;

let name = "Jane";
let write = () =>
  let hello = html({j|<div>Hello $name</div>|j}, ());
  render(hello, appElement);

open Expect;

describe("LitHtml", () =>
  test("#html does not throw", () =>
    expect(() =>
      write()
    ) |> not |> toThrow
  )
);