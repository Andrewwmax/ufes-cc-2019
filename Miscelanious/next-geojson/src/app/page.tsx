"use client";
import "ol/ol.css";

import React, { useCallback } from "react";
import { fromLonLat } from "ol/proj";
import GeoJSON from "ol/format/GeoJSON";
import { RMap, ROSM, RLayerVector, RStyle, RControl, RLayerTile } from "rlayers";

import geojsonFeatures from "../../data/southamericamemes.json";
import { Feature } from "ol";
import { LineString, Point } from "ol/geom";

const center = fromLonLat([-40.12736, -19.500781]);
export default function Simple(): JSX.Element {
	// basic map
	// return (
	// 	<RMap width={"100%"} height={"100dvh"} initial={{ center: center, zoom: 7 }}>
	// 		<ROSM />
	// 	</RMap>
	// );
	console.log(geojsonFeatures);
	const layersButton = <button>&#9776;</button>;

	return (
		<div>
			<RMap width={"100%"} height={"100dvh"} initial={{ center: center, zoom: 11 }}>
				{/* <ROSM /> */}
				<RControl.RLayers element={layersButton}>
					<ROSM properties={{ label: "OpenStreetMap" }} />
					<RLayerTile
						properties={{ label: "OpenTopo" }}
						url="https://mt1.google.com/vt/lyrs=s&x={x}&y={y}&z={z}"
						attributions="Google"
					/>
				</RControl.RLayers>
				<RLayerVector
					zIndex={10}
					/* Input data will have to be typed too */
					features={
						new GeoJSON({ featureProjection: "EPSG:3857" }).readFeatures(
							geojsonFeatures
						) as Feature<LineString>[]
					}
				>
					<RStyle.RStyle>
						<RStyle.RStroke color="#007bff" width={3} />
						<RStyle.RFill color="transparent" />
					</RStyle.RStyle>
				</RLayerVector>
			</RMap>
		</div>
	);
}
