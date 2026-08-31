.syntax unified
	.align 2, 0
	.global func_080C288C
	.thumb
	.thumb_func
	.type func_080C288C, %function
func_080C288C: @ 080C288C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	ldr r5, [r4, #0x00]
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r7, r5, r0
	ldr r1, _080C2938 @ =0x00000356
	adds r2, r5, r1
	ldr r1, _080C293C @ =0x0961A7D0
	movs r6, #0xD5
	lsls r6, r6, #0x02
	adds r0, r5, r6
	movs r3, #0x00
	ldsh r0, [r0, r3]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r3, #0x00
	ldsh r1, [r2, r3]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r1, r0
	blt _080C2912
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r1, [r4, #0x00]
	adds r1, r1, r6
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldr r0, [r4, #0x00]
	adds r2, r0, r6
	movs r0, #0x00
	ldsh r1, [r2, r0]
	movs r3, #0x0A
	ldsh r0, [r4, r3]
	adds r0, #0x07
	cmp r1, r0
	ble _080C28DC
	ldrh r0, [r4, #0x0A]
	strh r0, [r2, #0x00]
_080C28DC:
	ldr r0, [r4, #0x00]
	adds r0, r0, r6
	ldrb r0, [r0, #0x00]
	movs r1, #0x60
	bl func_080C213C
	ldr r3, _080C2940 @ =0x0961A82E
	ldr r2, [r4, #0x00]
	adds r2, r2, r6
	movs r1, #0x00
	ldsh r0, [r2, r1]
	adds r0, r0, r3
	movs r1, #0x00
	ldsb r1, [r0, r1]
	lsls r1, r1, #0x08
	ldr r0, [r5, #0x0C]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	movs r1, #0x00
	ldsh r0, [r2, r1]
	adds r0, r0, r3
	movs r1, #0x00
	ldsb r1, [r0, r1]
	lsls r1, r1, #0x08
	ldr r0, [r7, #0x0C]
	adds r0, r0, r1
	str r0, [r7, #0x0C]
_080C2912:
	ldr r1, [r4, #0x00]
	ldr r3, _080C2938 @ =0x00000356
	adds r1, r1, r3
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x1C
	bl AnimUpdate
	str r0, [r4, #0x14]
	adds r0, r4, #0x0
	adds r0, #0x34
	bl AnimUpdate
	str r0, [r4, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080C2938: .4byte 0x00000356
_080C293C: .4byte 0x0961A7D0
_080C2940: .4byte 0x0961A82E
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xFF, 0xF7, 0xA0, 0xFF, 0x0A, 0x48, 0x00, 0x68, 0xA0, 0x30, 0x00, 0x68
	.byte 0x00, 0x28, 0x0C, 0xD0, 0x43, 0xF7, 0x24, 0xFE, 0x00, 0x04, 0x00, 0x0C, 0x50, 0x21, 0x5A, 0xF0
	.byte 0x33, 0xFF, 0x00, 0x04, 0x00, 0x28, 0x02, 0xD1, 0x20, 0x1C, 0x01, 0xF0, 0x67, 0xF9, 0x10, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0x84, 0x9B, 0x03, 0x02
.syntax divided
