.syntax unified
	.align 2, 0
	.global func_08085844
	.thumb
	.thumb_func
	.type func_08085844, %function
func_08085844: @ 08085844
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r4, #0x00
	adds r0, r1, #0x0
	bl func_08085758
	adds r3, r0, #0x0
	movs r2, #0x00
	ldr r0, _080858A8 @ =0x0000FFFF
	mov r8, r0
	ldr r0, _080858AC @ =0x08F70AB0
	mov r12, r0
	ldr r6, _080858B0 @ =0x0203A080
	ldr r7, _080858B4 @ =0x00000FFF
_0808586A:
	lsls r0, r2, #0x01
	adds r1, r0, r3
	ldrh r0, [r1, #0x00]
	cmp r0, r8
	beq _08085892
	lsls r0, r0, #0x01
	adds r0, r0, r6
	ldrh r1, [r0, #0x00]
	adds r0, r7, #0x0
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	add r0, r12
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, r5
	bne _08085892
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_08085892:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x62
	bls _0808586A
	adds r0, r4, #0x0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080858A8: .4byte 0x0000FFFF
_080858AC: .4byte 0x08F70AB0
_080858B0: .4byte 0x0203A080
_080858B4: .4byte 0x00000FFF
.syntax divided
