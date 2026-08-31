.syntax unified
	.align 2, 0
	.global task_monsgage_0
	.thumb
	.thumb_func
	.type task_monsgage_0, %function
task_monsgage_0: @ 0805C9B4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	movs r0, #0x80
	lsls r0, r0, #0x02
	ldr r5, _0805C9F8 @ =0x08B255B4
	adds r1, r5, #0x0
	bl AllocObjTiles
	str r0, [r4, #0x00]
	movs r0, #0x80
	adds r1, r5, #0x0
	bl AllocObjTiles
	str r0, [r4, #0x04]
	ldr r0, _0805C9FC @ =0x08F69BA4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x08]
	movs r1, #0x00
	str r1, [r4, #0x10]
	str r1, [r4, #0x0C]
	ldr r0, _0805CA00 @ =0x08B2556C
	str r0, [r4, #0x14]
	ldr r0, _0805CA04 @ =0x08B2557C
	str r0, [r4, #0x18]
	strh r1, [r4, #0x1C]
	str r1, [r4, #0x20]
	adds r4, #0x24
	movs r0, #0x01
	strb r0, [r4, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_0805C9F8: .4byte 0x08B255B4
_0805C9FC: .4byte 0x08F69BA4
_0805CA00: .4byte 0x08B2556C
_0805CA04: .4byte 0x08B2557C
.syntax divided
