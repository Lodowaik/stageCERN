#!/usr/bin/env python3

import sys
import yoda


def normalize_yoda(infile, outfile, norm=1.0, include_overflows=True):

    aos = yoda.read(infile)

    n_histos = 0

    for path, ao in aos.items():

        # Only histogram-like objects implement normalize()
        if hasattr(ao, "normalize"):
            try:
                ao.normalize(norm, include_overflows)
                n_histos += 1
                print(f"Normalized {path}")
            except Exception as err:
                print(f"Skipping {path}: {err}")

    yoda.write(aos, outfile)

    print(f"\nNormalized {n_histos} histograms.")
    print(f"Output written to {outfile}")


if __name__ == "__main__":

    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} input.yoda output.yoda")
        sys.exit(1)

    normalize_yoda(sys.argv[1], sys.argv[2])
