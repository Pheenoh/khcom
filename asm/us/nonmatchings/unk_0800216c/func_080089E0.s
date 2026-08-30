.syntax unified
	.align 2, 0
	.global func_080089E0
	.thumb
	.thumb_func
	.type func_080089E0, %function
func_080089E0: @ 080089E0
	push {r4, r5, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	lsls r4, r1, #0x10
	asrs r3, r4, #0x10
	movs r0, #0x01
	ands r0, r3
	cmp r0, #0x00
	beq _080089FA
	adds r0, r3, r5
	subs r0, #0x01
	movs r1, #0x00
	strb r1, [r0, #0x00]
_080089FA:
	mov r1, sp
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r2, _08008A20 @ =0x040000D4
	str r1, [r2, #0x00]
	str r5, [r2, #0x04]
	lsrs r0, r4, #0x1F
	adds r0, r3, r0
	asrs r0, r0, #0x01
	movs r1, #0x81
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #0x08]
	ldr r0, [r2, #0x08]
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08008A20: .4byte 0x040000D4
.syntax divided
