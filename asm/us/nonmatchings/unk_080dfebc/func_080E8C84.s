.syntax unified
	.align 2, 0
	.global func_080E8C84
	.thumb
	.thumb_func
	.type func_080E8C84, %function
func_080E8C84: @ 080E8C84
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080E8C9C @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bge _080E8CCC
	b _080E8CF8
	.byte 0x00, 0x00
_080E8C9C: .4byte 0x0203C7AC
_080E8CA0:
	ldr r2, _080E8CBC @ =0x02034F7C
	ldrb r0, [r1, #0x01]
	lsls r0, r0, #0x03
	ldr r1, _080E8CC0 @ =0x0984CECC
	adds r0, r0, r1
	str r0, [r2, #0x00]
	ldr r2, _080E8CC4 @ =0x02034F84
	lsls r0, r4, #0x02
	ldr r1, _080E8CC8 @ =0x0203C598
	adds r0, r0, r1
	str r0, [r2, #0x00]
	movs r0, #0x01
	b _080E8CFA
	.byte 0x00, 0x00
_080E8CBC: .4byte 0x02034F7C
_080E8CC0: .4byte 0x0984CECC
_080E8CC4: .4byte 0x02034F84
_080E8CC8: .4byte 0x0203C598
_080E8CCC:
	movs r4, #0x00
	movs r0, #0x00
	bl func_080DEDD8
	adds r1, r0, #0x0
	b _080E8CF2
_080E8CD8:
	ldrb r0, [r1, #0x01]
	cmp r0, #0xFF
	beq _080E8CEA
	ldrb r0, [r1, #0x02]
	cmp r0, r6
	bne _080E8CEA
	ldrb r0, [r1, #0x03]
	cmp r0, r5
	beq _080E8CA0
_080E8CEA:
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r1, #0x08
_080E8CF2:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x05
	bne _080E8CD8
_080E8CF8:
	movs r0, #0x00
_080E8CFA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
