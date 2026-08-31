.syntax unified
	.align 2, 0
	.global task_bos_boogie_kaihuku_0
	.thumb
	.thumb_func
	.type task_bos_boogie_kaihuku_0, %function
task_bos_boogie_kaihuku_0: @ 080DB6A8
	push {r4, r5, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	movs r0, #0x02
	str r0, [r4, #0x00]
	movs r2, #0x00
	strh r2, [r4, #0x04]
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r0, r4, r3
	str r1, [r0, #0x00]
	subs r3, #0x04
	adds r0, r4, r3
	str r2, [r0, #0x00]
	ldr r2, [r1, #0x44]
	ldr r3, [r1, #0x48]
	movs r0, #0x80
	lsls r0, r0, #0x01
	adds r3, r3, r0
	ldr r0, [r1, #0x4C]
	ldr r1, _080DB734 @ =0xFFFF8400
	adds r0, r0, r1
	adds r5, r4, #0x0
	adds r5, #0x40
	ldr r1, _080DB738 @ =0x096FE114
	str r0, [sp, #0x000]
	adds r0, r5, #0x0
	bl func_0801B37C
	ldr r0, [r4, #0x74]
	ldr r1, [r4, #0x78]
	ldr r2, _080DB73C @ =0x00000400
	ldr r3, _080DB740 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x74]
	str r1, [r4, #0x78]
	ldr r0, _080DB744 @ =0x09799FB0
	adds r1, r2, #0x0
	bl LoadObjTiles
	str r0, [r4, #0x08]
	ldr r0, _080DB748 @ =0x0984AFB8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x0C]
	ldr r0, _080DB74C @ =0x08F69BC4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x10]
	adds r4, #0x14
	ldr r1, _080DB750 @ =0x09EF6820
	ldr r2, _080DB754 @ =0x09EF681C
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r5, #0x0
	bl func_0801BCD4
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DB734: .4byte 0xFFFF8400
_080DB738: .4byte 0x096FE114
_080DB73C: .4byte 0x00000400
_080DB740: .4byte 0x00000000
_080DB744: .4byte 0x09799FB0
_080DB748: .4byte 0x0984AFB8
_080DB74C: .4byte 0x08F69BC4
_080DB750: .4byte 0x09EF6820
_080DB754: .4byte 0x09EF681C
.syntax divided
