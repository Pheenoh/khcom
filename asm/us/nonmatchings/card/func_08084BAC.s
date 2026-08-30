.syntax unified
	.align 2, 0
	.global func_08084BAC
	.thumb
	.thumb_func
	.type func_08084BAC, %function
func_08084BAC: @ 08084BAC
	push {r4, r5, lr}
	movs r2, #0x00
	adds r1, r2, #0x0
	ldr r0, _08084BE4 @ =0x0203A858
	ldrh r0, [r0, #0x00]
	cmp r2, r0
	bcs _08084BDA
	ldr r5, _08084BE8 @ =0x0203A080
	ldr r4, _08084BEC @ =0x00000FFF
	adds r3, r0, #0x0
_08084BC0:
	lsls r0, r1, #0x01
	adds r0, r0, r5
	ldrh r0, [r0, #0x00]
	cmp r0, r4
	beq _08084BD0
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_08084BD0:
	adds r0, r1, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r3
	bcc _08084BC0
_08084BDA:
	adds r0, r2, #0x0
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08084BE4: .4byte 0x0203A858
_08084BE8: .4byte 0x0203A080
_08084BEC: .4byte 0x00000FFF
.syntax divided
