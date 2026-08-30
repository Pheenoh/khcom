.syntax unified
	.align 2, 0
	.global func_0810B434
	.thumb
	.thumb_func
	.type func_0810B434, %function
func_0810B434: @ 0810B434
	push {r4, r5, lr}
	ldr r5, _0810B488 @ =0x02036008
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	beq _0810B480
	ldr r1, _0810B48C @ =0x09EF9E04
	ldr r0, _0810B490 @ =0x0203600A
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r3, [r0, #0x00]
	ldr r4, _0810B494 @ =0x02036010
	ldr r2, _0810B498 @ =0x0203600C
	movs r1, #0x00
	ldsh r0, [r2, r1]
	adds r0, r3, r0
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x0C
	ldr r1, [r4, #0x00]
	subs r0, r0, r1
	asrs r0, r0, #0x03
	adds r1, r1, r0
	str r1, [r4, #0x00]
	ldrh r0, [r2, #0x00]
	adds r0, #0x01
	strh r0, [r2, #0x00]
	movs r1, #0x00
	ldsh r0, [r2, r1]
	adds r3, r3, r0
	movs r0, #0x00
	ldsb r0, [r3, r0]
	cmp r0, #0x00
	bne _0810B480
	strb r0, [r5, #0x00]
	str r0, [r4, #0x00]
_0810B480:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0810B488: .4byte 0x02036008
_0810B48C: .4byte 0x09EF9E04
_0810B490: .4byte 0x0203600A
_0810B494: .4byte 0x02036010
_0810B498: .4byte 0x0203600C
.syntax divided
