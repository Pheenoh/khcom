.syntax unified
	.align 2, 0
	.global func_08084FAC
	.thumb
	.thumb_func
	.type func_08084FAC, %function
func_08084FAC: @ 08084FAC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r3, #0x00
	movs r2, #0x00
	ldr r0, _08084FFC @ =0x0203A858
	ldrh r0, [r0, #0x00]
	cmp r3, r0
	bcs _08084FF4
	ldr r1, _08085000 @ =0x0203A080
	mov r12, r1
	ldr r4, _08085004 @ =0x00000FFF
	ldr r7, _08085008 @ =0x08F70AB0
	adds r5, r0, #0x0
_08084FC8:
	lsls r0, r2, #0x01
	add r0, r12
	ldrh r1, [r0, #0x00]
	cmp r1, r4
	beq _08084FEA
	adds r0, r4, #0x0
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	adds r0, r0, r7
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, r6
	bne _08084FEA
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_08084FEA:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r5
	bcc _08084FC8
_08084FF4:
	adds r0, r3, #0x0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08084FFC: .4byte 0x0203A858
_08085000: .4byte 0x0203A080
_08085004: .4byte 0x00000FFF
_08085008: .4byte 0x08F70AB0
.syntax divided
