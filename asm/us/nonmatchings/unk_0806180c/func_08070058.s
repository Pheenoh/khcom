.syntax unified
	.align 2, 0
	.global func_08070058
	.thumb
	.thumb_func
	.type func_08070058, %function
func_08070058: @ 08070058
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0x0
	adds r7, r1, #0x0
	ldrh r4, [r2, #0x3E]
	ldr r1, _0807007C @ =0x000001AB
	adds r0, r2, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x53
	beq _0807009E
	cmp r0, #0x53
	bgt _08070086
	cmp r0, #0x2D
	beq _0807009E
	cmp r0, #0x2D
	bgt _08070080
	cmp r0, #0x00
	beq _080700A4
	b _080700A8
_0807007C: .4byte 0x000001AB
_08070080:
	cmp r0, #0x40
	beq _0807009E
	b _080700A8
_08070086:
	cmp r0, #0xAD
	beq _080700A4
	cmp r0, #0xAD
	bgt _08070094
	cmp r0, #0x80
	beq _080700A4
	b _080700A8
_08070094:
	cmp r0, #0xC0
	beq _080700A4
	cmp r0, #0xD3
	bne _080700A8
	b _080700A4
_0807009E:
	movs r0, #0x01
	orrs r4, r0
	b _080700A8
_080700A4:
	ldr r0, _080700D0 @ =0x0000FFFE
	ands r4, r0
_080700A8:
	movs r0, #0xBE
	lsls r0, r0, #0x01
	adds r6, r2, r0
	ldr r0, [r6, #0x00]
	adds r5, r2, #0x0
	adds r5, #0x28
	cmp r7, r0
	beq _080700C2
	adds r0, r5, #0x0
	adds r1, r7, #0x0
	bl func_0801CD74
	str r7, [r6, #0x00]
_080700C2:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_0801CE00
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080700D0: .4byte 0x0000FFFE
.syntax divided
