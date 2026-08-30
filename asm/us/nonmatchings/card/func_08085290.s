.syntax unified
	.align 2, 0
	.global func_08085290
	.thumb
	.thumb_func
	.type func_08085290, %function
func_08085290: @ 08085290
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r4, #0x00
	bl func_08085740
	adds r1, r0, #0x0
	ldrh r0, [r1, #0x00]
	ldr r2, _080852D4 @ =0x0000FFFF
	cmp r0, r2
	beq _080852BA
_080852A6:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x63
	beq _08085314
	lsls r0, r4, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	cmp r0, r2
	bne _080852A6
_080852BA:
	lsls r0, r4, #0x01
	adds r0, r0, r1
	strh r5, [r0, #0x00]
	ldr r0, _080852D8 @ =0x02034AB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _08085300
	cmp r0, #0x01
	bgt _080852DC
	cmp r0, #0x00
	beq _080852EC
	b _080852E0
	.byte 0x00, 0x00
_080852D4: .4byte 0x0000FFFF
_080852D8: .4byte 0x02034AB0
_080852DC:
	cmp r0, #0x02
	beq _08085318
_080852E0:
	ldr r3, _080852E8 @ =0x0203A080
	lsls r4, r5, #0x01
	b _0808532A
	.byte 0x00, 0x00
_080852E8: .4byte 0x0203A080
_080852EC:
	ldr r3, _080852FC @ =0x0203A080
	lsls r4, r5, #0x01
	adds r2, r4, r3
	ldrh r1, [r2, #0x00]
	movs r5, #0x80
	lsls r5, r5, #0x05
	b _08085324
	.byte 0x00, 0x00
_080852FC: .4byte 0x0203A080
_08085300:
	ldr r3, _08085310 @ =0x0203A080
	lsls r4, r5, #0x01
	adds r2, r4, r3
	ldrh r1, [r2, #0x00]
	movs r5, #0x80
	lsls r5, r5, #0x06
	b _08085324
	.byte 0x00, 0x00
_08085310: .4byte 0x0203A080
_08085314:
	movs r0, #0x00
	b _08085360
_08085318:
	ldr r3, _08085368 @ =0x0203A080
	lsls r4, r5, #0x01
	adds r2, r4, r3
	ldrh r1, [r2, #0x00]
	movs r5, #0x80
	lsls r5, r5, #0x07
_08085324:
	adds r0, r5, #0x0
	orrs r0, r1
	strh r0, [r2, #0x00]
_0808532A:
	adds r0, r4, r3
	ldrh r0, [r0, #0x00]
	bl func_080609AC
	lsls r0, r0, #0x10
	ldr r4, _0808536C @ =0x02039DE0
	ldr r3, _08085370 @ =0x02034AB0
	ldrb r2, [r3, #0x00]
	lsls r1, r2, #0x03
	subs r1, r1, r2
	lsls r1, r1, #0x05
	adds r1, r1, r4
	adds r1, #0xDA
	lsrs r0, r0, #0x10
	ldrh r2, [r1, #0x00]
	adds r0, r0, r2
	strh r0, [r1, #0x00]
	ldrb r1, [r3, #0x00]
	lsls r0, r1, #0x03
	subs r0, r0, r1
	lsls r0, r0, #0x05
	adds r0, r0, r4
	adds r0, #0xDC
	ldrh r1, [r0, #0x00]
	adds r1, #0x01
	strh r1, [r0, #0x00]
	movs r0, #0x01
_08085360:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08085368: .4byte 0x0203A080
_0808536C: .4byte 0x02039DE0
_08085370: .4byte 0x02034AB0
.syntax divided
