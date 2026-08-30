.syntax unified
	.align 2, 0
	.global func_081204E0
	.thumb
	.thumb_func
	.type func_081204E0, %function
func_081204E0: @ 081204E0
	push {r4, lr}
	ldr r0, _0812053C @ =0x03007FF0
	ldr r2, [r0, #0x00]
	ldr r3, [r2, #0x00]
	ldr r0, _08120540 @ =0x68736D53
	cmp r3, r0
	beq _08120534
	ldr r0, _08120544 @ =0x040000C6
	movs r4, #0xB6
	lsls r4, r4, #0x08
	adds r1, r4, #0x0
	strh r1, [r0, #0x00]
	adds r0, #0x0C
	strh r1, [r0, #0x00]
	ldrb r0, [r2, #0x04]
	movs r0, #0x00
	strb r0, [r2, #0x04]
	adds r0, r3, #0x0
	subs r0, #0x0A
	str r0, [r2, #0x00]
	ldr r3, _08120548 @ =0x04000006
	ldrb r0, [r3, #0x00]
	ldr r1, [r2, #0x10]
	cmp r0, #0x9F
	bne _0812051A
	adds r2, r3, #0x0
_08120514:
	ldrb r0, [r2, #0x00]
	cmp r0, #0x9F
	beq _08120514
_0812051A:
	ldr r2, _08120548 @ =0x04000006
_0812051C:
	ldrb r0, [r2, #0x00]
	cmp r0, #0x9F
	bne _0812051C
	ldr r4, _0812054C @ =0x04000100
	ldr r0, _08120550 @ =0x00044940
	bl __divsi3
	negs r0, r0
	strh r0, [r4, #0x00]
	ldr r1, _08120554 @ =0x04000102
	movs r0, #0x80
	strh r0, [r1, #0x00]
_08120534:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0812053C: .4byte 0x03007FF0
_08120540: .4byte 0x68736D53
_08120544: .4byte 0x040000C6
_08120548: .4byte 0x04000006
_0812054C: .4byte 0x04000100
_08120550: .4byte 0x00044940
_08120554: .4byte 0x04000102
.syntax divided
