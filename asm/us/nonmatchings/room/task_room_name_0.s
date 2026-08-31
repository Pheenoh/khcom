.syntax unified
	.align 2, 0
	.global task_room_name_0
	.thumb
	.thumb_func
	.type task_room_name_0, %function
task_room_name_0: @ 080F7BF8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	ldr r0, _080F7C7C @ =0x0993AF64
	movs r1, #0x80
	lsls r1, r1, #0x04
	bl LoadObjTiles
	str r0, [r5, #0x00]
	ldr r0, _080F7C80 @ =0x099910C4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	ldr r0, _080F7C84 @ =0x09EF8DA4
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x08]
	str r4, [r5, #0x30]
	movs r0, #0xB8
	lsls r0, r0, #0x07
	str r0, [r5, #0x0C]
	movs r1, #0x8A
	lsls r1, r1, #0x08
	str r1, [r5, #0x10]
	movs r0, #0xF0
	lsls r0, r0, #0x07
	str r0, [r5, #0x14]
	str r1, [r5, #0x18]
	movs r0, #0x80
	lsls r0, r0, #0x03
	str r0, [r5, #0x20]
	movs r2, #0x19
	str r2, [r5, #0x24]
	movs r1, #0x00
	movs r0, #0x00
	strh r0, [r5, #0x2A]
	strh r0, [r5, #0x2C]
	adds r0, r5, #0x0
	adds r0, #0x28
	strb r1, [r0, #0x00]
	str r2, [r5, #0x1C]
	adds r4, r5, #0x0
	adds r4, #0x3C
	adds r0, r4, #0x0
	movs r1, #0x24
	bl func_08065ACC
	movs r0, #0x01
	bl _08066468
	str r0, [r5, #0x38]
	ldr r1, _080F7C88 @ =0x09EF7048
	ldr r0, [r5, #0x30]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	adds r1, r4, #0x0
	bl func_08065B6C
	adds r1, r5, #0x0
	adds r1, #0x34
	strb r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080F7C7C: .4byte 0x0993AF64
_080F7C80: .4byte 0x099910C4
_080F7C84: .4byte 0x09EF8DA4
_080F7C88: .4byte 0x09EF7048
.syntax divided
