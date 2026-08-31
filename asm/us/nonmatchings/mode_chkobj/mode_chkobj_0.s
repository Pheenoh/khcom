.syntax unified
	.align 2, 0
	.global mode_chkobj_0
	.thumb
	.thumb_func
	.type mode_chkobj_0, %function
mode_chkobj_0: @ 0800B354
	push {r4, r5, r6, lr}
	bl func_08004DB0
	ldr r5, _0800B3FC @ =0x0203489C
	movs r0, #0x48
	bl EwramAlloc
	str r0, [r5, #0x00]
	movs r1, #0x01
	bl TaskPoolInit
	ldr r0, [r5, #0x00]
	ldr r1, _0800B400 @ =0x09EE9190
	movs r2, #0x00
	bl TaskCreate
	ldr r0, [r5, #0x00]
	movs r6, #0x00
	movs r4, #0x00
	strh r4, [r0, #0x14]
	strh r4, [r0, #0x16]
	strh r4, [r0, #0x18]
	movs r0, #0x80
	lsls r0, r0, #0x06
	movs r1, #0x00
	bl AllocObjTiles
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x1C]
	ldr r0, _0800B404 @ =0x08F683A4
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, [r5, #0x00]
	str r0, [r1, #0x20]
	ldr r0, _0800B408 @ =0x088B629C
	str r0, [r1, #0x3C]
	adds r1, #0x40
	strb r6, [r1, #0x00]
	ldr r1, [r5, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x42
	ldr r0, _0800B40C @ =0x000080A0
	strh r0, [r2, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x44
	strh r4, [r0, #0x00]
	adds r0, #0x02
	strh r4, [r0, #0x00]
	ldr r4, _0800B410 @ =0x0812E744
	ldr r0, [r4, #0x00]
	bl func_0800B30C
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x0F
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x00
	bl func_08004FC8
	movs r1, #0xA8
	lsls r1, r1, #0x07
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x01
	bl func_0805FA8C
	ldr r1, _0800B414 @ =0x08128304
	movs r0, #0x01
	movs r2, #0x20
	movs r3, #0x0F
	bl func_0805FA60
	ldr r3, [r4, #0x08]
	movs r0, #0xA6
	movs r1, #0x00
	movs r2, #0x02
	bl func_0805FCB0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0800B3FC: .4byte 0x0203489C
_0800B400: .4byte 0x09EE9190
_0800B404: .4byte 0x08F683A4
_0800B408: .4byte 0x088B629C
_0800B40C: .4byte 0x000080A0
_0800B410: .4byte 0x0812E744
_0800B414: .4byte 0x08128304
.syntax divided
