module D = Webapi.Dom;
module Doc = D.Document;
let appElement = Doc.getElementById("app", D.document);

open Jest;
open Expect;
open LitHtml;

exception NoSuchElement;

let name = "Jane";
let writeHtml = () => {
  let hello = html([%bs.raw "html`blablah`"]);
  switch (appElement) {
  | Some(appElement) => render(hello, `element(appElement))
  | None => raise(NoSuchElement)
  };
};
let writeSvg = () => {
  let hello = svg([%bs.raw "html`<g/>`"]);
  switch (appElement) {
  | Some(appElement) => render(hello, `element(appElement))
  | None => raise(NoSuchElement)
  };
};

describe("LitHtml", () => {
  test("#html does not throw", () =>
    expect(() =>
      writeHtml()
    ) |> not |> toThrow
  );

  test("#svg does not throw", () =>
    expect(() =>
      writeSvg()
    ) |> not |> toThrow
  );

  test("#render does not throw", () =>
    expect(() => {
      let tmpl = html([%bs.raw "html`blablah`"]);
      render(tmpl);
    })
    |> not
    |> toThrow
  );
});