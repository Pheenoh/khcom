.syntax unified
	.align 2, 0
	.global mode_ms_top_2
	.thumb
	.thumb_func
	.type mode_ms_top_2, %function
mode_ms_top_2: @ 08102500
	push {r4, r5, r6, lr}
	ldr r0, _08102578 @ =0x020357CC
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, _0810257C @ =0x020357C8
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, _08102580 @ =0x020357D4
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, _08102584 @ =0x020357D0
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, _08102588 @ =0x020357F4
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, _0810258C @ =0x020357F0
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, _08102590 @ =0x02035814
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, _08102594 @ =0x02035810
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	movs r4, #0x00
	ldr r6, _08102598 @ =0x02035820
	ldr r5, _0810259C @ =0x02035818
_08102548:
	ldm r6!, {r0}
	bl ReleaseObjPalette
	ldm r5!, {r0}
	bl ReleaseObjTiles
	adds r4, #0x01
	cmp r4, #0x01
	ble _08102548
	ldr r0, _081025A0 @ =0x0203585C
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, _081025A4 @ =0x02035858
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, _081025A8 @ =0x020358A8
	bl TaskPoolDestroy
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08102578: .4byte 0x020357CC
_0810257C: .4byte 0x020357C8
_08102580: .4byte 0x020357D4
_08102584: .4byte 0x020357D0
_08102588: .4byte 0x020357F4
_0810258C: .4byte 0x020357F0
_08102590: .4byte 0x02035814
_08102594: .4byte 0x02035810
_08102598: .4byte 0x02035820
_0810259C: .4byte 0x02035818
_081025A0: .4byte 0x0203585C
_081025A4: .4byte 0x02035858
_081025A8: .4byte 0x020358A8
.syntax divided
