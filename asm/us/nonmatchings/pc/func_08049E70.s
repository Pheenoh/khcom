.syntax unified
	.align 2, 0
	.global func_08049E70
	.thumb
	.thumb_func
	.type func_08049E70, %function
func_08049E70: @ 08049E70
	push {r4, r5, r6, lr}
	mov r12, r0
	adds r6, r2, #0x0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	mov r4, r12
	mov r3, r12
	adds r3, #0x40
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08049EA0
	movs r2, #0xAE
	lsls r2, r2, #0x01
	add r2, r12
	lsls r1, r5, #0x10
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x04]
	subs r0, r0, r1
	b _08049EAE
_08049EA0:
	movs r2, #0xAE
	lsls r2, r2, #0x01
	add r2, r12
	lsls r1, r5, #0x10
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x04]
	adds r0, r0, r1
_08049EAE:
	str r0, [r2, #0x00]
	movs r0, #0xB0
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, [r3, #0x08]
	str r0, [r1, #0x00]
	movs r0, #0xB8
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x19
	str r0, [r1, #0x00]
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0x00
	strh r2, [r0, #0x00]
	adds r1, #0x38
	add r1, r12
	negs r0, r6
	str r0, [r1, #0x00]
	movs r0, #0xC6
	lsls r0, r0, #0x01
	add r0, r12
	strh r2, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
