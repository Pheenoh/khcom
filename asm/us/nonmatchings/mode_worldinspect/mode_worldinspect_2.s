.syntax unified
	.align 2, 0
	.global mode_worldinspect_2
	.thumb
	.thumb_func
	.type mode_worldinspect_2, %function
mode_worldinspect_2: @ 08100448
	push {r4, r5, r6, lr}
	ldr r0, _081004C0 @ =0x0203511C
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, _081004C4 @ =0x02035120
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, _081004C8 @ =0x02035124
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, _081004CC @ =0x02035128
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, _081004D0 @ =0x02035148
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, _081004D4 @ =0x0203514C
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	movs r5, #0x00
	ldr r6, _081004D8 @ =0x02035168
_0810047E:
	lsls r4, r5, #0x02
	ldr r0, [r6, #0x00]
	cmp r0, #0x00
	beq _0810048A
	bl ReleaseObjPalette
_0810048A:
	ldr r0, _081004DC @ =0x02035198
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08100498
	bl ReleaseObjTiles
_08100498:
	adds r6, #0x04
	adds r5, #0x01
	cmp r5, #0x0B
	ble _0810047E
	ldr r0, _081004E0 @ =0x020351F8
	movs r1, #0x18
	bl func_08065AE0
	ldr r0, _081004E4 @ =0x020352C0
	movs r1, #0x3C
	bl func_08065AE0
	ldr r0, _081004E8 @ =0x020354D4
	ldr r0, [r0, #0x00]
	bl EwramFree
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081004C0: .4byte 0x0203511C
_081004C4: .4byte 0x02035120
_081004C8: .4byte 0x02035124
_081004CC: .4byte 0x02035128
_081004D0: .4byte 0x02035148
_081004D4: .4byte 0x0203514C
_081004D8: .4byte 0x02035168
_081004DC: .4byte 0x02035198
_081004E0: .4byte 0x020351F8
_081004E4: .4byte 0x020352C0
_081004E8: .4byte 0x020354D4
.syntax divided
