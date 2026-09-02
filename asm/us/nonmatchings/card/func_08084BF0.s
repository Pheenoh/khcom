.syntax unified
	.align 2, 0
	.global func_08084BF0
	.thumb
	.thumb_func
	.type func_08084BF0, %function
func_08084BF0: @ 08084BF0
	push {r4, r5, r6, r7, lr}
	movs r3, #0x00
	adds r2, r3, #0x0
	ldr r0, _08084C34 @ =0x0203A858
	ldrh r0, [r0, #0x00]
	cmp r3, r0
	bcs _08084C2A
	ldr r7, _08084C38 @ =0x0203A080
	ldr r5, _08084C3C @ =0x00000FFF
	movs r6, #0xE0
	lsls r6, r6, #0x07
	adds r4, r0, #0x0
_08084C08:
	lsls r0, r2, #0x01
	adds r0, r0, r7
	ldrh r1, [r0, #0x00]
	cmp r1, r5
	beq _08084C20
	adds r0, r6, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08084C20
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_08084C20:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r4
	bcc _08084C08
_08084C2A:
	adds r0, r3, #0x0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08084C34: .4byte 0x0203A858
_08084C38: .4byte 0x0203A080
_08084C3C: .4byte 0x00000FFF
.syntax divided
