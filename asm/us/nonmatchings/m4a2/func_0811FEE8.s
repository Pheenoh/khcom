.syntax unified
	.align 2, 0
	.global func_0811FEE8
	.thumb
	.thumb_func
	.type func_0811FEE8, %function
func_0811FEE8: @ 0811FEE8
	push {lr}
	lsls r0, r0, #0x10
	ldr r3, _0811FF14 @ =0x09D6F60C
	ldr r1, _0811FF18 @ =0x09D6F744
	lsrs r0, r0, #0x0D
	adds r0, r0, r1
	ldrh r2, [r0, #0x04]
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r1, r1, r3
	ldr r1, [r1, #0x00]
	ldr r3, [r1, #0x00]
	ldr r2, [r0, #0x00]
	cmp r3, r2
	beq _0811FF1C
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	bl func_08120650
	b _0811FF38
	.byte 0x00, 0x00
_0811FF14: .4byte 0x09D6F60C
_0811FF18: .4byte 0x09D6F744
_0811FF1C:
	ldr r2, [r1, #0x04]
	ldrh r0, [r1, #0x04]
	cmp r0, #0x00
	bne _0811FF2E
	adds r0, r1, #0x0
	adds r1, r3, #0x0
	bl func_08120650
	b _0811FF38
_0811FF2E:
	cmp r2, #0x00
	bge _0811FF38
	adds r0, r1, #0x0
	bl func_0811FDA8
_0811FF38:
	pop {r0}
	bx r0
.syntax divided
