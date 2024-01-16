"use client";

import "ol/ol.css";

import React, { useCallback, useRef } from "react";
import { fromLonLat } from "ol/proj";
import GeoJSON from "ol/format/GeoJSON";
// import { RMap, ROSM, RLayerVector, RStyle, RControl, RLayerTile } from "rlayers";
import { RStyle, RControl } from "rlayers";

import { Feature } from "ol";
import { LineString, Point } from "ol/geom";

import geojsonFeatures from "../../data/southamericamemes.json";

import dynamic from "next/dynamic";

const RMap = dynamic(() => import("rlayers").then((module) => module.RMap), { ssr: false });
const ROSM = dynamic(() => import("rlayers").then((module) => module.ROSM), { ssr: false });
const RLayerVector = dynamic(() => import("rlayers").then((module) => module.RLayerVector), { ssr: false });
// const RStyle = dynamic(() => import("rlayers").then((module) => module.RStyle), { ssr: false });
// const RControl = dynamic(() => import("rlayers").then((module) => module.RControl), { ssr: false });
const RLayerTile = dynamic(() => import("rlayers").then((module) => module.RLayerTile), { ssr: false });
// const DynamicHeader = dynamic(() => import "ol/ol.css", {
// 	ssr: false,
// });

const center = fromLonLat([-40.12736, -19.500781]);
export default function Simple(): JSX.Element {
	// basic map
	// return (
	// 	<RMap width={"100%"} height={"100dvh"} initial={{ center: center, zoom: 7 }}>
	// 		<ROSM />
	// 	</RMap>
	// );
	// console.log(geojsonFeatures);
	const layersButton = <button className="layersButton">&#9776;</button>;

	return (
		<div>
			<RMap width={"100%"} height={"100dvh"} initial={{ center: center, zoom: 11 }}>
				{/* <ROSM /> */}
				{/* <RControl.RLayers element={layersButton}> */}
				{/* <ROSM properties={{ label: "OpenStreetMap" }} /> */}
				<RLayerTile
					properties={{ label: "Google Maps satellite" }}
					url="https://mt1.google.com/vt/lyrs=s&x={x}&y={y}&z={z}"
					attributions="Google"
				/>
				{/* </RControl.RLayers> */}
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
